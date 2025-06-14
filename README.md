# Mario PRO2

## Descripción
Este programa esta inspirado en el videojuego de Mario Bros, donde un personaje (Mario) tiene que saltar entre plataformas hasta llegar a una bandera donde logra ganar la partida.

## Instalación
Para poder ejecutar este código es necesario tener instalado, para tu comodidad, Make y un compilador de C++ preferiblemente g++ para mantener la similitud con el proyecto.

Una vez tengamos todas las dependencias instaladas, ejecutaremos los comandos `make clean`i `make MODE=release` en este orden para poder crear una build del proyecto y finalmente podremos ejecutar el proyecto con `./mario_pro_2.exe`.

## Uso
Una vez el programa esté ejecutandose veremos una pantalla con plataformas, setas flotando y un personaje llamado Mario.
Aquí podremos mover el personaje con las flechas del teclado. Si pulsamos la flecha derecha, el Mario se moverá hacia la derecha y viceversa con la izquierda. Si pulsamos la tecla superior, saltará y volverá al suelo. En el juego hay Goombas que puedes llegar a matar a Mario, hay Lifes que dan vidas a Mario para que tarde mas en morir a causa de los Goombas y una bandera que al tocarla Mario gana el juego. Mario empieza con una vida, en la consola se pueden ir viendo las vidas que gana y pierde.
Para pausar el juego podemos pulsar la letra `P` y así no podremos movernos del sitio por muchas teclas que pulsemos ni los enemigos podran matarnos.
Finalmente, para cerrar el programa se puede hacer pulsando la tecla `Esc` del teclado o la cruz de la pantalla arriba a la derecha.

## Novedades de la Parte 3
- Nueva clase Goomba. Un Goomba es un enemigo que al tocarlo, Mario pierde una vida. Este enemigo se mueve de derecha a izquierda y viceversa, sin salirse de su plataforma con el objetivo de quitarle todas las vidas a Mario.
- Nueva clase Flag. Una FLag es un objeto del mapa que hay que alcanzar para poder ganar el juego. Si aun no se ha tocado, el objeto permanecera con una bandera negra y la letra `B` (de Bowser, el enemigo de Mario). Una vez Mario toque la bandera esta se volvera de color rojo y con la letra `M` de Mario, indicando que se ha ganado la partida.
- Al acabar el juego, se paran todos los controles de Mario y dependiendo de si se ha ganado o no se muestra un texto por pantalla u otro. Si se ha ganado se podra ver un `YOU WON`, si has perdido veras un `GAME OVER`.
- He cambiado el vector de vidas por una lista para poder eliminar las vidas cuando el Mario las coja.
- He cambiado el vector de plataformas por una lista.
- He añadido una opcion al principio de ejecutar el programa para elejir cuantas plataformas i vidas quieres en el juego.
- Estan todas las funciones comentadas con su descripcion correspondiente