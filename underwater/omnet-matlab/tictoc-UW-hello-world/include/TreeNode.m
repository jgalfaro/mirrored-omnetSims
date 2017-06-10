
%   Copyright 2008 The MathWorks, Inc.

classdef TreeNode < handle
% TREENODE    Provides tree implementation.
%   The purpose of this class is to provide a tree implementation by
%   connecting nodes with left, right, up, and down handles.
    
    properties (GetAccess = public, SetAccess = private, Hidden)    
        %UP Handle to the up node
        Up = [];
        
        %DOWN Handle to the down node. There can be many nodes down the
        %hierarchy.        
        Down = [];
        
        %LEFT Handle to the left node 
        Left = [];
        
        %RIGHT Handle to the right node 
        Right = [];        
    end
    
    properties (GetAccess = public, SetAccess = private, Hidden, Dependent)
        % LeftMostDown - Handle to the node that is the left most directly
        % under                
        LeftMostDown;
        
        % RightMostDown - Handle to the node that is the right most directly
        % under 
        RightMostDown;
        
        % DirectSuccessors - Cell array of the tree nodes directly under the
        % current node
        DirectSuccessors;
    end
    
    methods                
        connectUp(obj,objParent)
        %connectUp   Connect current node to the parent given by objParent
        %   connectUp(obj,objParent) Will connect obj to the parent
        %   objParent
    end    
    
    methods (Access = protected)
        function disconnect(obj)
            % disconnect Disconnect current node from right, left, and up.
            %   disconnect(obj) The left, up, and right nodes can still
            %   access the current node but this node can not            
            obj.Up = [];
            obj.Right = [];
            obj.Left = [];
        end
        
        function disconnectDown(obj)
            % disconnectDown Disconnect from childs.
            obj.Down = [];
        end
    end
        
    methods                                                   
        function childObj = get.LeftMostDown(obj)
            childObj = obj.Down;
            if ~isempty(childObj)                
                while ~isempty(childObj.Left)
                    childObj = childObj.Left;
                end
            end
        end
                
        function childObj = get.RightMostDown(obj)
            childObj = obj.Down;
            if ~isempty(childObj)                
                while ~isempty(childObj.Right)
                    childObj = childObj.Right;
                end
            end
        end
        
        function objChilds = get.DirectSuccessors(obj)
            objChilds = {};
            currentChild = obj.LeftMostDown;
            while ~isempty(currentChild)
                objChilds{end+1} = currentChild;
                currentChild = currentChild.Right;
            end
        end
    end
           
end