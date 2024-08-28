### SUSHI BAR PROBLEM ### 

Ovaj repozitorijum predstavlja projektni rad iz predmeta Arhitektura računara i operativni sistemi. U pitanju je rešenje problema SUSHI BAR iz knjige Little Book of Semaphores.

Ovaj projekat simulira scenario u restoranu gdje gosti jedu sushi koristeći niti i semafore za sinhronizaciju. Projekt je napisan u programskom jeziku C.

Tekst problema u originalu glasi:

Imagine a sushi bar with 5 seats. If you arrive while there is an empty seat, you can take a seat immediately. But if you arrive when all 5 seats are full, that means that all of them are dining together, and you will have to wait for the entire party to leave before you sit down.This problem was inspired by a problem proposed by Kenneth Reek.

## Struktura repozitorijuma ## 

**sushi.c**: Glavni izvorni kod koji simulira situaciju u restoranu koristeći niti i semafore. Program kreira 10 gostiju (niti) koji dolaze u restoran i zauzimaju slobodna mjesta kako bi jeli sushi. Ako su sva mjesta zauzeta, gosti čekaju svoj red dok se neko mjesto ne oslobodi.  Upotrebljava se semafor za kontrolu pristupa ograničenom broju stolica.
**Makefile**: Skripta koja se koristi za kompajliranje izvornog koda.
**README.md**:  Ovaj dokument pruža osnovne informacije o projektu, uključujući uputstva za kompajliranje i pokretanje programa. 

## Kako pokrenuti projekat ##

Makefile je fajl koji je neophodan za kompajliranje ovog programa. Da bi se pokrenuo, dovoljno je u terminalu doći do foldera u kome se nalazi fajl sa kodom, i izvršiti komandu `make`. On se može pokrenuti izvršavanjem komande `./a.out`

## Zahtjevi ##

- GCC kompajler sa podrškom za `-pthread`.
- Linux operativni sistem sa podrškom za POSIX niti.

## Dodatne napomene ##

Ovaj projekat je razvijen kao primjer rada sa nitima i semaforima u C jeziku.
