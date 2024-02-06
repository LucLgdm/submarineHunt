# submarineHunt  
The submarine hunt is a school project that I did im 2019. It's a real-time game.  

A submarine is know to move through an area and you want to know precisely where it is. I'm order to discover it you can throw many sonar nat. 2 shapes are possible : a straight row or a grid pattern. You only have to input the coordinates of 2 of the sonar.  
When the submarine goes near a sonar, this one turn to red until the submarine is far enough away. In the end you never see the submarine, you only have an idea of its position.  

The base element is a brick (brique.h), with a brick we can build a sonar (bouee.h) and the submarine (sousmarin.h). The submarine follows a way created by the class direction.  util.h is a class usefull in some calculation.  
In order to manage the time I use the kerneksynchroniser class. 

