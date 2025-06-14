# Mario PRO2

## Descripción
Este programa esta inspirado en el videojuego de Mario Bros, donde un personaje (Mario) tiene que saltar entre plataformas hasta llegar al final del mapa donde logra ganar la partida.

## Instalación
Para poder ejecutar este código es necesario tener instalado, para tu comodidad, Make y un compilador de C++ preferiblemente g++ para mantener la similitud con el proyecto.

Una vez tengamos todas las dependencias instaladas, ejecutaremos los comandos `make clean`i `make MODE=release` en este orden para poder crear una build del proyecto y finalmente podremos ejecutar el proyecto con `./mario_pro_2.exe`.

## Uso
Una vez el programa esté ejecutandose veremos una pantalla con plataformas, setas flotando y un personaje llamado Mario.
Aquí podremos mover el personaje con las flechas del teclado. Si pulsamos la flecha derecha, el Mario se moverá hacia la derecha y viceversa con la izquierda. Si pulsamos la barra de espacio, saltará y volverá al suelo. Para pausar el juego podemos pulsar la letra `P` y así no podremos movernos del sitio por muchas teclas que pulsemos.
Finalmente, para cerrar el programa se puede hacer pulsando la tecla `ESC` del teclado o la cruz de la pantalla arriba a la derecha.

## Novedades de la Parte 3
- Nueva clase Goomba. Un Goomba es un enemigo que al tocarlo, Mario pierde una vida. Este enemigo se mueve de derecha a izquierda y viceversa, sin salirse de su plataforma con el objetivo de quitarle todas las vidas a Mario.
- Nueva clase Flag. \\falta completar\\
- He cambiado el vector de vidas por una lista para poder eliminar las vidas cuando el Mario las coja.
- He cambiado el vector de plataformas por una lista.
- He añadido una opción al principio de ejecutar el programa para elejir cuantas plataformas, vidas, enemigos (Goombas) i etc quiere el usuario en el juego, si no se especifica ninguna cantidad se ponen valores por defecto.
- Estan todas las funciones comentadas con su descripcion correspondiente

TODO:
comentar cosas nuevas del codigo en el readme
hacer 4 clases nuevas
    palo con bandera del final del juego
    ...
    ...
cambiar los vectores de game por listas para usar punteros
