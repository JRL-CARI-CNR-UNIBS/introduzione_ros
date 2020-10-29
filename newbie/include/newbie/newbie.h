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


/* I file .h hanno bisogno delle guardia
 * https://stackoverflow.com/questions/4767068/header-guards-in-c-and-c
 * C'è un alternativa per pigri: https://en.wikipedia.org/wiki/Pragma_once
 */
#ifndef NEWBIE202010290932
#define NEWBIE202010290932


/* è buona norma usare un namespace per distiguire le funzioni e le classi di questo pacchetto da altre.
 * Ad esempio se si dichiara una funzione "sum" in più pacchetti quale devo usare?
 * https://www.html.it/pag/15500/namespace-2/
 */
namespace newbie {

/* dichiaro la funzione somma che restituisce un interno e riceva in ingresso tre variabili.
 * Le variabili sono definite per riferimento (la & dopo int), che detta rozzamente significa
 * passare l'area di memoria dal chiamante alla funzione
 * come succede con i puntatori senza la rogna di usare i puntatori.
 * Qui è spiegato un filo meglio: https://www.tutorialspoint.com/pointers-vs-references-in-cplusplus
 * Questo metodo consente di velocizzare molto il programma evitando copia di memoria.
 * Se voglio evitare copie di memoria ma anche impedire che la funzione possa cambiare il valore alla variabile
 * posso usare const all'inizio. Se la funzione prova a modificare la variabile c'è un errore in compilazione.
 * Guardando la definizione di sum, passo tre variabili. "a" e "b" non sono modificabili, "c" lo è.
 * La definizione della funzione è nel file src/newbie/newbie.cpp
 */

int sum(const int& a, const int& b, int& c);
}


#endif

