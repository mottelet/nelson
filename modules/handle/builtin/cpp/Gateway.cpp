//=============================================================================
// Copyright (c) 2016-present Allan CORNET (Nelson)
//=============================================================================
// This file is part of the Nelson.
//=============================================================================
// LICENCE_BLOCK_BEGIN
// SPDX-License-Identifier: LGPL-3.0-or-later
// LICENCE_BLOCK_END
//=============================================================================
#include "NelsonGateway.hpp"
//=============================================================================
#include "deleteBuiltin.hpp"
#include "getBuiltin.hpp"
#include "invokeBuiltin.hpp"
#include "ismethodBuiltin.hpp"
#include "ispropBuiltin.hpp"
#include "isvalidBuiltin.hpp"
#include "methodsBuiltin.hpp"
#include "propertiesBuiltin.hpp"
#include "setBuiltin.hpp"
//=============================================================================
#include "generic_eq_handleBuiltin.hpp"
#include "handle_deleteBuiltin.hpp"
#include "handle_displayBuiltin.hpp"
#include "handle_eq_genericBuiltin.hpp"
#include "handle_eq_handleBuiltin.hpp"
#include "handle_fieldnamesBuiltin.hpp"
#include "handle_getBuiltin.hpp"
#include "handle_horzcat_handleBuiltin.hpp"
#include "handle_invokeBuiltin.hpp"
#include "handle_isequalBuiltin.hpp"
#include "handle_ismethodBuiltin.hpp"
#include "handle_ispropBuiltin.hpp"
#include "handle_isvalidBuiltin.hpp"
#include "handle_methodsBuiltin.hpp"
#include "handle_propertiesBuiltin.hpp"
#include "handle_setBuiltin.hpp"
#include "handle_vertcat_handleBuiltin.hpp"
//=============================================================================
using namespace Nelson;
//=============================================================================
const std::wstring gatewayName = L"handle";
//=============================================================================
static const nlsGateway gateway[] = {
    { "delete", (ptrBuiltin)Nelson::HandleGateway::deleteBuiltin, 0, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "get", (ptrBuiltin)Nelson::HandleGateway::getBuiltin, 1, 1, CPP_BUILTIN_WITH_EVALUATOR },
    { "set", (ptrBuiltin)Nelson::HandleGateway::setBuiltin, 1, 1, CPP_BUILTIN_WITH_EVALUATOR },
    { "invoke", (ptrBuiltin)Nelson::HandleGateway::invokeBuiltin, 1, 2,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "isvalid", (ptrBuiltin)Nelson::HandleGateway::isvalidBuiltin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "methods", (ptrBuiltin)Nelson::HandleGateway::methodsBuiltin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "properties", (ptrBuiltin)Nelson::HandleGateway::propertiesBuiltin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "isprop", (ptrBuiltin)Nelson::HandleGateway::ispropBuiltin, 1, 2,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "ismethod", (ptrBuiltin)Nelson::HandleGateway::ismethodBuiltin, 1, 2,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "handle_vertcat_handle", (ptrBuiltin)Nelson::HandleGateway::handle_vertcat_handleBuiltin, 1,
        2 },
    { "handle_horzcat_handle", (ptrBuiltin)Nelson::HandleGateway::handle_horzcat_handleBuiltin, 1,
        2 },
    { "handle_eq_handle", (ptrBuiltin)Nelson::HandleGateway::handle_eq_handleBuiltin, 1, 2 },
    { "generic_eq_handle", (ptrBuiltin)Nelson::HandleGateway::generic_eq_handleBuiltin, 1, 2 },
    { "handle_eq_generic", (ptrBuiltin)Nelson::HandleGateway::handle_eq_genericBuiltin, 1, 2 },
    { "handle_isequal", (ptrBuiltin)Nelson::HandleGateway::handle_isequalBuiltin, 1, 2 },
    { "handle_isequaln", (ptrBuiltin)Nelson::HandleGateway::handle_isequalBuiltin, 1, 2 },
    { "handle_isequalto", (ptrBuiltin)Nelson::HandleGateway::handle_isequalBuiltin, 1, 2 },

    { "handle_get", (ptrBuiltin)Nelson::HandleGateway::handle_getBuiltin, 1, 1 },
    { "handle_set", (ptrBuiltin)Nelson::HandleGateway::handle_setBuiltin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "handle_invoke", (ptrBuiltin)Nelson::HandleGateway::handle_invokeBuiltin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "handle_display", (ptrBuiltin)Nelson::HandleGateway::handle_displayBuiltin, 0, 2,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "handle_disp", (ptrBuiltin)Nelson::HandleGateway::handle_displayBuiltin, 0, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "handle_delete", (ptrBuiltin)Nelson::HandleGateway::handle_deleteBuiltin, 0, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "handle_isvalid", (ptrBuiltin)Nelson::HandleGateway::handle_isvalidBuiltin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "handle_fieldnames", (ptrBuiltin)Nelson::HandleGateway::handle_fieldnamesBuiltin, 1, 1,
        CPP_BUILTIN_WITH_EVALUATOR },
    { "handle_methods", (ptrBuiltin)Nelson::HandleGateway::handle_methodsBuiltin, 1, 1 },
    { "handle_ismethod", (ptrBuiltin)Nelson::HandleGateway::handle_ismethodBuiltin, 1, 2 },
    { "handle_isprop", (ptrBuiltin)Nelson::HandleGateway::handle_ispropBuiltin, 1, 2 },
    { "handle_properties", (ptrBuiltin)Nelson::HandleGateway::handle_propertiesBuiltin, 1, 1 },
};
//=============================================================================
NLSGATEWAYFUNC(gateway)
//=============================================================================
NLSGATEWAYINFO(gateway)
//=============================================================================
NLSGATEWAYREMOVE(gateway)
//=============================================================================
NLSGATEWAYNAME()
//=============================================================================
