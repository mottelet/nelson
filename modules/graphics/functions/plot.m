%=============================================================================
% Copyright (c) 2016-present Allan CORNET (Nelson)
%=============================================================================
% This file is part of the Nelson.
%=============================================================================
% LICENCE_BLOCK_BEGIN
% SPDX-License-Identifier: LGPL-3.0-or-later
% LICENCE_BLOCK_END
%=============================================================================
function varargout = plot(varargin)
  inputArguments = varargin;
  nbInputArguments = nargin;
  if (nbInputArguments >= 2)
    if ((length(inputArguments{1}) == 1) && isgraphics(inputArguments{1}, 'axes'))
      go = inputArguments{1}(1);
      inputArguments(1) = [];
      nbInputArguments = nbInputArguments - 1;
    else   
      go = newplot();
    end
  else
    go = newplot();
  end
  saveca = gca();
  axes(go);
  propertyIndex = 0;
  if (nbInputArguments > 2)
    propertyIndex = nbInputArguments - 1;
    bContinue = 1;
    while ((propertyIndex >= 1) && bContinue)
      bContinue = ischar(inputArguments{propertyIndex}) && isValidGraphicsProperty('line', inputArguments{propertyIndex});
      if bContinue
        propertyIndex = propertyIndex - 2;
      end
    end
    propertyIndex = propertyIndex + 2;
  end
  
  propertiesList = {};
  if ((propertyIndex > 0) & (propertyIndex < nbInputArguments))
    propertiesList = inputArguments(propertyIndex:end);
    inputArguments(propertyIndex:end) = [];
  end
  
  h = [];
  while (~isempty(inputArguments))
    cs = '';
    ms = '';
    ps = '';
    if (length(inputArguments) == 1)
      if isempty(h)
        h = plot_Y(inputArguments{1},go,propertiesList);
      else
        h = [h; plot_Y(inputArguments{1},go,propertiesList)];
      end
      inputArguments(1) = [];
    else
      [ps, cs, ms, msg] = colstyle(inputArguments{2}, 'plot', false);
      r = isempty(msg);
      if (r)
        h = [h; plot_Y(inputArguments{1},go,completeProperties(cs,ms,ps,propertiesList))];
        inputArguments(1:2) = [];
      elseif (length(inputArguments) ==2)
        if isempty(h)
          h = plot_XY(inputArguments{1},inputArguments{2},go,propertiesList);
        else
          h = [h; plot_XY(inputArguments{1},inputArguments{2},go,propertiesList)];
        end
        inputArguments(1:2) = [];
      else
        [ps, cs, ms, msg] = colstyle(inputArguments{3}, 'plot', false);
        r = isempty(msg);
        if (r)
          h = [h; plot_XY(inputArguments{1},inputArguments{2},go, completeProperties(cs,ms,ps,propertiesList))];
          inputArguments(1:3) = [];
        else
          if (isempty(h))
            h = plot_XY(inputArguments{1}, inputArguments{2}, go, propertiesList);
          else
            h = [h; plot_XY(inputArguments{1}, inputArguments{2}, go, propertiesList)];
          end
          inputArguments(1:2) = [];
        end
      end
    end
  end
  axes(saveca);
  if (nargout > 0)
    varargout{1} = h;
  end
end
%=============================================================================
function q = completeProperties(cs, ms, ps, p)
  if isempty(ps)
    ps = 'none';
  end
  if (strcmp(cs, ''))
    q = {'Marker', ms, 'LineStyle', ps, p{:}};
  else
    q = {'Color', cs, 'Marker', ms, 'LineStyle', ps, 'MarkerEdgeColor', cs, 'MarkerFaceColor', cs, p{:}};
  end
end
%=============================================================================
function color = getColorAndUpdateIndex(go)
  colorOrder = go.ColorOrder;
  if isempty (colorOrder)
    color = [0 0 0];
    return;
  end
  colorIndex = go.ColorOrderIndex;
  nbColors = size (colorOrder, 1);
  colorIndex = mod (colorIndex, nbColors);
  if (colorIndex == 0)
    colorIndex = nbColors;
  elseif (colorIndex < 0)
    colorIndex = 1;
  end
  color = colorOrder(colorIndex, :);
  if (colorIndex >= nbColors)
    colorIndex = colorIndex + 1;
    colorIndex = mod (colorIndex, nbColors);
    if (colorIndex == 0)
      colorIndex = 1;
    end
    lineStyleOrderIndex = go.LineStyleOrderIndex;
    go.LineStyleOrderIndex = lineStyleOrderIndex + 1;
  else
     colorIndex = colorIndex + 1;
  end
  go.ColorOrderIndex = colorIndex;
end
%=============================================================================
function lineStyle = getLineStyleAndUpdateIndex(go)
  lineStyleOrder = go.LineStyleOrder;
  if isempty (lineStyleOrder)
    lineStyle = '-';
    return;
  end
  if ischar(lineStyleOrder)
    lineStyleOrder = cellstr(lineStyleOrder);
  end
  LineStyleOrderIndex = go.LineStyleOrderIndex;
  numberOfStyles = size(lineStyleOrder, 1);
  LineStyleOrderIndex = mod (LineStyleOrderIndex, numberOfStyles);
  if (LineStyleOrderIndex == 0)
    LineStyleOrderIndex = numberOfStyles;
  elseif (LineStyleOrderIndex < 0)
    LineStyleOrderIndex = 1;
  end
  lineStyle = lineStyleOrder{LineStyleOrderIndex};
end
%=============================================================================
function k = plotVector(go, x, y, lineProperties)
  lineStyle = getLineStyleAndUpdateIndex(go);
  color = getColorAndUpdateIndex(go);
  if (~any(strcmp(lineProperties, 'Color')))
    lineProperties = [lineProperties, {'MarkerEdgeColor', color, 'MarkerFaceColor', color}];
  end
  if (~any(strcmp(lineProperties, 'LineStyle')))
    lineProperties = [lineProperties, {'LineStyle', lineStyle}];
  end  
  k = __line__('XData', x, 'YData', y, 'Color', color, lineProperties{:});
end
%=============================================================================
function h = plot_XY(X, Y, go, lineProperties)
  h = [];
  [X, Y] = matchMatrix(X,Y);
  if (isvector(X))
    X = X(:);
  end;
  if (isvector(Y))
    Y = Y(:); 
  end;
  for i=1:size(Y, 2)
    h = [h; plotVector(go, X(:,i), Y(:,i), lineProperties)];
  end
end
%=============================================================================
function [a, b] = matchMatrix(a ,b)
  if (isvector(a) && ~isvector(b))
    if (length(a) == size(b,1))
      a = repmat(a(:),[1,size(b,2)]);
      return
    else
      if (length(a) == size(b,2))
        b = b';
        a = repmat(a(:)',[size(b,2),1])';
        return
      else
        error(_('Dimensions do not match.'));
      end
    end
  end
  if (~isvector(a) && isvector(b))
    if (length(b) == size(a,1))
      b = repmat(b(:),[1,size(a,2)]);
    else
      if (length(b) == size(a,2))
        a = a';
        b = repmat(b(:)',[size(a,2),1])';
      else
        error(_('Dimensions do not match.'));
      end
    end
  end
end
%=============================================================================
function h = plot_Y(Y, go, lineProperties)
  h = [];
  if (isvector(Y)) Y = Y(:); end;
  if (isreal(Y))
    n = 1:size(Y,1);
    for i=1:size(Y,2)
      h = [h; plotVector(go, n, Y(:,i), lineProperties)];
    end
  else
    for i=1:size(Y,2)
      h = [h; plotVector(go, real(Y(:,i)), imag(Y(:,i)), lineProperties)];
    end      
  end
end
%=============================================================================

