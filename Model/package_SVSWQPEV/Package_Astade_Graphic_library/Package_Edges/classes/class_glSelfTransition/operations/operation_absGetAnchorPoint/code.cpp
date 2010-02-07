glVector diff = myNode.absGetPosition() - absGetPosition();
diff = diff.Dir();
diff *= my_Radius;

return absGetPosition() - diff;
