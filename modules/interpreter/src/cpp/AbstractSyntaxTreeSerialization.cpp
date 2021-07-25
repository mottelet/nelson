//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// Alternatively, you can redistribute it and/or
// modify it under the terms of the GNU General Public License as
// published by the Free Software Foundation; either version 2 of
// the License, or (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this program. If not, see <http://www.gnu.org/licenses/>.
// LICENCE_BLOCK_END
//=============================================================================
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#ifdef _MSC_VER
#include <winsock2.h>
#else
#include <netinet/in.h>
#endif
#include "AbstractSyntaxTree.hpp"
#include "PlatformInfo.hpp"
//=============================================================================
namespace Nelson {
//=============================================================================
static void
writeBytes(std::vector<char>& data, const void* buffer, int len)
{
    char* ptr = (char*)buffer;
    for (int k = 0; k < len; ++k) {
        data.push_back(ptr[k]);
    }
}
//=============================================================================
static void
readBytes(const std::vector<char>& data, size_t& pos, void* buffer, int len)
{
    char* ptr = (char*)buffer;
    memcpy(ptr, &data.data()[pos], len);
    pos = pos + len;
}
//=============================================================================
static void
sendSignature(char type, int count, std::vector<char>& data)
{
    writeBytes(data, &type, 1);
    long netcount = htonl(count);
    writeBytes(data, &netcount, sizeof(long));
}
//=============================================================================
static void
checkSignature(const std::vector<char>& data, size_t& pos, char expectedType, int expectedCount)
{
    char rtype = 0;
    long rcount = 0;
    readBytes(data, pos, &rtype, 1);
    readBytes(data, pos, &rcount, sizeof(long));
    rcount = ntohl(rcount);
    if (expectedType != rtype) {
        Error(_W("Serialization Type Mismatch."));
    }
    if (expectedCount != rcount) {
        Error(_W("Serialization Size Mismatch."));
    }
}
//=============================================================================
static void
putInts(int* buffer, int len, std::vector<char>& data)
{
    sendSignature('i', len, data);
    writeBytes(data, buffer, len * sizeof(int));
}
//=============================================================================
static void
putInt(int value, std::vector<char>& data)
{
    putInts(&value, 1, data);
}
//=============================================================================
static void
getInts(const std::vector<char>& data, size_t& pos, int* ptr, int count)
{
    checkSignature(data, pos, 'i', count);
    readBytes(data, pos, ptr, count * sizeof(int));
    if (IsBigEndian()) {
        char* cptr = (char*)ptr;
        for (int i = 0; i < 4 * count; i += 4) {
            std::swap(cptr[i], cptr[i + 3]);
            std::swap(cptr[i + 1], cptr[i + 2]);
        }
    }
}
//=============================================================================
static int
getInt(const std::vector<char>& data, size_t& pos)
{
    int* ptr = new int[1];
    getInts(data, pos, ptr, 1);
    int t = ptr[0];
    delete[] ptr;
    return t;
}
//=============================================================================
static void
putBytes(const char* buffer, int len, std::vector<char>& data)
{
    sendSignature('c', len, data);
    writeBytes(data, buffer, len * sizeof(char));
}
//=============================================================================
static void
putByte(char value, std::vector<char>& data)
{
    putBytes(&value, 1, data);
}
//=============================================================================
static void
getBytes(const std::vector<char>& data, size_t& pos, char* ptr, int count)
{
    checkSignature(data, pos, 'c', count);
    readBytes(data, pos, ptr, count * sizeof(char));
}
//=============================================================================
static char
getByte(const std::vector<char>& data, size_t& pos)
{
    char* ptr = new char[1];
    getBytes(data, pos, ptr, 1);
    char t = ptr[0];
    delete[] ptr;
    return t;
}
//=============================================================================
static std::string
getString(const std::vector<char>& data, size_t& pos)
{
    checkSignature(data, pos, 'x', 0);
    unsigned int len = 0;
    getInts(data, pos, (int*)&len, 1);
    if (len == 0) {
        return std::string();
    }
    char* cp = new char[len + 1];
    getBytes(data, pos, cp, len);
    cp[len] = 0;
    std::string res(cp);
    delete[] cp;
    return res;
}
//=============================================================================
static void
putString(const std::string& str, std::vector<char>& data)
{
    int len;
    sendSignature('x', 0, data);
    if (str.empty()) {
        len = 0;
        putInts((int*)&len, 1, data);
    } else {
        len = (int)str.length();
        putInts((int*)&len, 1, data);
        putBytes(str.data(), len, data);
    }
}
//=============================================================================
void
AbstractSyntaxTree::serialize(AbstractSyntaxTreePtr expr, std::vector<char>& data)
{
    if (expr == nullptr) {
        putByte(0, data);
        return;
    }
    putByte(1, data);
    putByte(expr->type, data);
    putInt(expr->tokenNumber, data);
    putInt(expr->m_context, data);
    putByte(expr->opNum, data);
    putString(expr->text, data);
    serialize(expr->down, data);
    serialize(expr->right, data);
}
//=============================================================================
AbstractSyntaxTreePtr
AbstractSyntaxTree::unserialize(const std::vector<char>& data)
{
    size_t pos = 0;
    return unserialize(pos, data);
}
//=============================================================================
AbstractSyntaxTreePtr
AbstractSyntaxTree::unserialize(size_t& pos, const std::vector<char>& data)
{
    AbstractSyntaxTreePtr ptr = nullptr;
    char flag = getByte(data, pos);
    if (!flag) {
        return nullptr;
    }
    ptr = new AbstractSyntaxTree();
    ptr->type = (NODE_TYPE)getByte(data, pos);
    ptr->tokenNumber = getInt(data, pos);
    ptr->m_context = getInt(data, pos);
    ptr->opNum = (OP_TYPE)getByte(data, pos);
    ptr->text = getString(data, pos);
    ptr->down = unserialize(pos, data);
    ptr->right = unserialize(pos, data);
    return ptr;
}
//=============================================================================
} // namespace Nelson
//=============================================================================
