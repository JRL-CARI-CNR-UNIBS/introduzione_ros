/*
Copyright (c) 2020, Manuel Beschi 
CARI Joint Research Lab
UNIBS-DIMI manuel.beschi@unibs.it
CNR-STIIMA manuel.beschi@stiima.cnr.it
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the <organization> nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/


/* nota: lo standard di ROS prevede che i pacchetti scritti in C++ abbiano due sottocartelle: src e include.
 * include contiene gli header file.
 * Tecnicamente potrebbero stare nella cartella include/ ed essere inclusi con il comando
 * #include <nome_del_file.h>
 * Tuttavia se più di un pacchetto ha un file chiamato "nome_del_file.h" il compilatore non sa a quale riferirsi e prende il primo.
 * Per evitare questa ambiguita in ROS si è scelto di avere una sottocartella di include chiamata come il pacchetto dove mettere i file .h.
 * In questo modo per includere il file bisogna specificare anche il percorso relativo:
 * #include <nome_del_pacchetto/nome_del_file.h>
 *
 * src contiene dei file cpp con il codice dei vari nodi.
 * Ha poi una sottocartella (per simmetria con includedef) chiamata come il pacchetto (newbie in questo caso)
 * che contiene la definizione delle funzioni e classi dichiarate nelle librerie.
 * NOTA: https://www.studytonight.com/cpp/functions-in-cpp.php
 */



// elenco degli include file necessari, ovviamente dipende dall'applicazione
#include <ros/ros.h>  // il "core" di ros
#include <newbie/newbie.h>  // header con funzioni e classi definite in questo pacchetto

int main(int argc, char **argv)
{
  ros::init(argc, argv, "node");
  ros::NodeHandle nh;

  int a=1;
  int b=1;
  int c;
  int d;

  d=newbie::sum(a,b,c);
  ROS_INFO("c=%d, d=%d",c,d);

  return 0;
}
