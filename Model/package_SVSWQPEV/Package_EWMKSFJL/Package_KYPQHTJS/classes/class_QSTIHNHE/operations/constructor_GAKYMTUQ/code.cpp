floatingMatrix[edge][edge] = 0;
floatingMatrix[normal][normal] = 120;
floatingMatrix[label][label] = 5;
floatingMatrix[interface][interface] = 40;

floatingMatrix[edge][normal] = 30;
floatingMatrix[normal][edge] = 30;

floatingMatrix[edge][label] = 0;
floatingMatrix[label][edge] = 0;

floatingMatrix[edge][interface] = 25;
floatingMatrix[interface][edge] = 25;

floatingMatrix[normal][label] = 5;
floatingMatrix[label][normal] = 5;

floatingMatrix[normal][interface] = 40;
floatingMatrix[interface][normal] = 40;

floatingMatrix[label][interface] = 20;
floatingMatrix[interface][label] = 20;

