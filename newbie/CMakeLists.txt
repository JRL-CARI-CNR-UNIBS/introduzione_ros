# cmake (https://en.wikipedia.org/wiki/CMake)
# è un linguaggio usato per generare dei makefile, cioè le istruzioni per il compilatore.
cmake_minimum_required(VERSION 2.8.3)
project(newbie) # nome del pacchetto
add_compile_options(-std=c++11) # Compilo in C++ Versione 11


## dipendenze
# find package cerca altri pacchetti installati sulla macchina, e crea le variabili per la compilazione e il linking.
# cercando ad esempio il pacchetto catkin si hanno le variabili
# ${catkin_LIBRARIES}  lista delle librerie (collezioni di funzioni C++) del programma
# ${catkin_INCLUDE_DIRS} elenco delle directory che contengono degli header file (.h) richiesti da catkin
#
# catkin è il tool di compilazione di ROS, con find_package(catkin) si cerca quindi la presenza di ROS.
# Visto che trovare ROS è necessario, la parola chiave REQUIRED da un errore se non è stato trovato
# Essendo ROS modulare dobbiamo specificare anche quali pacchetti (components, nella terminolagia di CMAKE) ci servono.
# In questo esempio uso i pacchetti: roscpp (per usare ROS in C++) e std_msgs
find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

# allo stesso modo si possono cercare anche altri software fuori da ROS. In questo esempio, una libreria matematica chiamata Eigen
find_package(Eigen3 REQUIRED)


# il comando catkin_package serve dare informazioni al CMAKE delle dipendenze del pacchetto in essere, delle sue librerie e i percorsi alle directory che contengono degli header file.
# queste informazioni sono utili agli altri pacchetti che dipenderanno da questo pacchetto
catkin_package(
 INCLUDE_DIRS include  # cartella che contiene gli include file . Finirà in ${catkin_INCLUDE_DIRS} nei pacchetti che dipendono da questo pacchetto
 LIBRARIES newbie # elenco delle librerie contenuto in questo pacchetto. Finirà in ${catkin_LIBRARIES} nei pacchetti che dipendono da questo pacchetto. Normalmente se c'è solo una libreria questa si chiama come il pacchetto.
 CATKIN_DEPENDS roscpp std_msgs # dipendenze ROS di questo pacchetto. I pacchetti che dipendo da questo pacchetto dipenderanno anche da roscpp e std_msgs
 DEPENDS Eigen3 # dipendenze non ROS di questo pacchetto. I pacchetti che dipendo da questo pacchetto dipenderanno anche da Eigen3.
)

## header file
# include le directory con gli header file da usare in compilazione
include_directories(
  include  # header file di questo pacchetto
  ${catkin_INCLUDE_DIRS} # header file dei pacchetti da cui dipende questo pacchetto
  ${Eigen3_INCLUDE_DIRS} # header file dei pacchetti da cui dipende questo pacchetto
)

## aggiungo librerie (funzioni che possono essere usate da nodi di questo pacchetto ma anche da altri pacchetti) per la compilazione
add_library(newbie src/newbie/newbie.cpp)

## aggiungo eseguibili (nodi ROS) per la compilazione
# il comando add_executable crea un nodo chiamato "node" il cui codice è definito in src/prova.cpp
add_executable(node src/prova.cpp)

# il comando add_dependencies definisce le dipendenze del nodo chiamato "node", sono automaticamente aggiunte alle variabili  ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS}.
add_dependencies(node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

# aggiungo i link alle libreria di altri pacchetti con il comando target_link_libraries
target_link_libraries(node
  newbie #link la librearia newbie
  ${catkin_LIBRARIES}
)
# Curiosità: potrei aggiungere anche ${EIGEN3_LIBRARIES} ma Eigen3 è una libreria di soli header files
# https://eigen.tuxfamily.org/dox/GettingStarted.html
# Nota: info di base su compilazione e linking: https://www.cplusplus.com/articles/2v07M4Gy/
