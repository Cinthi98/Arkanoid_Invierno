# BRICKS BREACKER

En este examen implementé el patrón SINGLETON, que es usado cuando queremos que sólo haya una cosa o instancia de algo, como en este caso queremos que haya solo un actor de bomba en pantalla en el momento.
Para hacer la bomba cree una nueva clase con dicho nombre e hice que al momento de chocar con algún brick la bomba se oculte y luego aumente el alcance de su colisión para así dar el efecto de explosión.
Las clases que se llegó a usar fueron el Paddle.h, PaddlePlayerController.h y también el cpp, seguido de la clase bomba.h y cpp, al igual en la clase brick.cpp y es allí donde se especifican la mayor cantidad de pasos que se usó.

El botón para lanzar la bomba es la "T" y si se intenta lanzar más de 1 al mismo tiempo manda un mensaje diciendo que ya existe.
