﻿# Proiect2_Gradina

Acest proiect este menit să aprofundeze noțiuni ale programării orientate pe obiect (POO) precum interfețe, clase abstracte, funcții virtuale, excepții, dynamic / static cast și multe altele. (noțiuni de bază sunt găsite în proiectul1 -» COFETĂRIE «-)

ȘCENARIU:

Este primăvara anului 2024 și vremea este perfectă pentru a "grădinări". Astfel, la țară, la bunici, decizi să înființezi o grădină care conține numeroase plante. Totuși, nefiind expert, alegi să începi cu florile, legumele, fructele și pomii devenind o problemă pentru altă dată. Așadar, îți vin în ajutor cu următoarele idei:
1. prima oară vrem să înțelegem plantele la modul general (PLANTA -» devine interfața noastră, clasă neinstanțiabilă care conține doar funcții virtuale pure)
2. vrem să ne axăm doar pe flori pentru a face grădina colorată și frumos mirositoare (FLOARE -» devine clasă abstractă, neinstanțiabilă, care conține funcții virtuale, virtuale pure, funcții și variabile proprii; DE CE facem asta? Știm ce este o floare       la modul general dar putem să "mergem mai adânc" și să o particularizăm. Totodată "general" este un cuvânt cheie, orice floare are anumite proprietăți dar nu orice floare are proprietățile florii X, de unde și clasele derivate ce vor urma)
3. ne decidem să cumpărăm bujori, trandafiri și floarea soarelui pe care le plantăm în grădină și care au boboci (clase derivate, instanțiabile în care avem funcții și variabile specifice)
4. cu trecerea timpului avem grijă de grădină: dacă o floare e ofilită o scoatem (funcții de atenționare sau de culegere a semințelor specifice claselor derivate pe care le putem apela în urma dynamic_cast-ului), adăugăm îngrășământ bobocilor (doar     
   bujorilor pentru că sunt flori fragile -» din nou dynamic cast); totuși "ce e prea mult strică" și avem grijă să nu punem prea mult îngrășământ (excepții care vor prinde astfel de cazuri)
5. ne bucurăm de flori!

Aceasta este o scurtă prezentare. Mai multe noțiuni și exemple sunt găsite în cod (variabile și funcții statice, regula celor 5, etc.)
