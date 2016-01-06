//~~ glFloatingConstants() [glFloatingConstants] ~~
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

floatingMatrix[normal][interface] = 80;
floatingMatrix[interface][normal] = 80;

floatingMatrix[label][interface] = 20;
floatingMatrix[interface][label] = 20;

floatingMatrix[edge][invisible] = 20;
floatingMatrix[invisible][edge] = 20;

floatingMatrix[normal][invisible] = 10;
floatingMatrix[invisible][normal] = 10;

floatingMatrix[label][invisible] = 3;
floatingMatrix[invisible][label] = 3;

floatingMatrix[interface][invisible] = 0;
floatingMatrix[invisible][interface] = 0;

floatingMatrix[invisible][invisible] = 40;

