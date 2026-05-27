# ✈️ Air-OOP România - Sistem de Management Aerian

**Descriere**
Bine ai venit la bord! Ești managerul general al companiei aeriene Air-OOP România. Misiunea ta este să coordonezi zborurile zilnice, să gestionezi echipajul (piloți experimentați și însoțitori de zbor) și să te asiguri că biletele sunt vândute eficient, fără a depăși capacitatea aeronavelor. Ai grijă, un zbor supra-rezervat va declanșa o eroare critică în sistem!

**Funcționalități**
Meniu Interactiv — interfață în consolă care îți permite să adaugi bilete, să verifici zborurile și să vezi statistici în timp real.
Sistem de Siguranță — sistemul previne supra-rezervarea (Overbooking) aruncând o excepție personalizată ExceptieCapacitate dacă încerci să vinzi bilete peste limita avionului.
Gestiunea Echipajului — angajarea personalului se face automatizat printr-un AngajatFactory, iar conducerea este asigurată de un ManagerCompanie.
Registre Universale — stocarea biletelor și a notificărilor se face prin clasa șablon Registru<T>.
Sortare Inteligentă — la afișarea unui zbor, biletele sunt sortate descrescător în funcție de preț, folosind funcții lambda.
Statistici Globale — urmărirea numărului total de bilete emise la nivel de companie folosind variabile și metode statice.

**Instrucțiuni**
Pentru a rula sistemul de management:
-Compilează proiectul folosind CMake (sau rulează executabilul generat de IDE-ul tău).
-Odată pornit, Managerul va declara sistemul deschis.
-Urmărește meniul afișat în consolă și tastează numărul corespunzător acțiunii dorite (ex: 1 pentru a vinde un bilet nou).
-Introdu datele cerute de sistem (Nume pasager, Clasă, Preț, Loc).

**Stări de execuție (Exemple de Rulare)**
*Sistem de Securitate - Capacitate Depășită:*
<img width="770" height="261" alt="image" src="https://github.com/user-attachments/assets/45ecb18c-29c7-40bf-93a7-afdabb50de62" />


*Meniul Principal și Zboruri cu Succes:*
<img width="773" height="652" alt="image" src="https://github.com/user-attachments/assets/48cf21b2-2df0-4ed6-a61a-428378d30221" />

## Instrucțiuni de compilare

Proiectul este configurat cu CMake.

Instrucțiuni pentru terminal:

1. Pasul de configurare
```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
# sau ./scripts/cmake.sh configure
```

Sau pe Windows cu GCC:
```sh
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug -G Ninja
# sau ./scripts/cmake.sh configure -g Ninja
```

La acest pas putem cere să generăm fișiere de proiect pentru diverse medii de lucru.

## Cerințe obligatorii

Nerespectarea duce la nepunctarea proiectului

  - programul va fi scris în C++
  - programul va avea un meniu interactiv (doar pentru ilustrarea funcționalității)
  - programul nu are erori de compilare
  - fară variabile globale
  - datele membre private(sau protected)
  - GitHub Actions trecute
  - commit-uri pe Git adecvate si punctuale
  - folosirea a funcționalităților limbajului fără sens
  - folosirea a funcționlităților limbajului cu scopul de a încălca "legal" o altă regulă
      - folosirea excesivă a claselor friend
      - folosirea excesviă a elementelor statice
  - lipsa separarea implementarii de definitie

## Cerințe
- pentru fiecare cerință (sau subcerință) neîndeplinită se scade **1** punct
- [ ] definirea a minim **2-3 ieararhii de clase** care sa interactioneze in cadrul temei alese (fie prin compunere, agregare sau doar sa apeleze metodele celeilalte intr-un mod logic)
  - minim o clasa cu:
    - [ ] constructori de inițializare [*](https://github.com/Ionnier/poo/tree/main/labs/L02#crearea-obiectelor)
    - [ ] constructor supraîncărcat [*](https://github.com/Ionnier/poo/tree/main/labs/L02#supra%C3%AEnc%C4%83rcarea-func%C8%9Biilor)
    - [ ] constructori de copiere [*](https://github.com/Ionnier/poo/tree/main/labs/L02#crearea-obiectelor)
    - [ ] `operator=` de copiere [*](https://github.com/Ionnier/poo/tree/main/labs/L02#supra%C3%AEnc%C4%83rcarea-operatorilor)
    - [ ] destructor [*](https://github.com/Ionnier/poo/tree/main/labs/L02#crearea-obiectelor)
    - [ ] `operator<<` pentru afișare (std::ostream) [*](https://github.com/Ionnier/poo/blob/main/labs/L02/fractie.cpp#L123)
    - [ ] `operator>>` pentru citire (std::istream) [*](https://github.com/Ionnier/poo/blob/main/labs/L02/fractie.cpp#L128)
    - [ ] alt operator supraîncărcat ca funcție membră [*](https://github.com/Ionnier/poo/blob/main/labs/L02/fractie.cpp#L32)
    - [ ] alt operator supraîncărcat ca funcție non-membră [*](https://github.com/Ionnier/poo/blob/main/labs/L02/fractie.cpp#L39) - nu neaparat ca friend
  - in derivate
      - [ ] implementarea funcționalităților alese prin [upcast](https://github.com/Ionnier/poo/tree/main/labs/L04#solu%C8%9Bie-func%C8%9Bii-virtuale-late-binding) și [downcast](https://github.com/Ionnier/poo/tree/main/labs/L04#smarter-downcast-dynamic-cast)
        - aceasta va fi făcută prin **2-3** metode specifice temei alese
        - funcțiile pentru citire / afișare sau destructorul nu sunt incluse deși o să trebuiască să le implementați 
      - [ ] apelarea constructorului din clasa de bază din [constructori din derivate](https://github.com/Ionnier/poo/tree/main/labs/L04#comportamentul-constructorului-la-derivare)
      - [ ] suprascris [cc](https://github.com/Ionnier/poo/tree/main/labs/L04#comportamentul-constructorului-de-copiere-la-derivare)/op= pentru copieri/atribuiri corecte
      - [ ] destructor [virtual](https://github.com/Ionnier/poo/tree/main/labs/L04#solu%C8%9Bie-func%C8%9Bii-virtuale-late-binding)
  - pentru celelalte clase se va definii doar ce e nevoie
  - minim o ierarhie mai dezvoltata (cu 2-3 clase dintr-o clasa de baza)
  - ierarhie de clasa se considera si daca exista doar o clasa de bază însă care nu moștenește dintr-o clasă din altă ierarhie
- [ ] cât mai multe `const` [*](https://github.com/Ionnier/poo/tree/main/labs/L04#reminder-const-everywhere)
- [ ] funcții și atribute `static` (în clase) [*](https://github.com/Ionnier/poo/tree/main/labs/L04#static)
  - [ ] 1+ atribute statice non-triviale 
  - [ ] 1+ funcții statice non-triviale
- [ ] excepții [*](https://github.com/Ionnier/poo/tree/main/labs/L04#exception-handling)
  - porniți de la `std::exception`
  - ilustrați propagarea excepțiilor
  - ilustrati upcasting-ul în blocurile catch
  - minim folosit într-un loc în care tratarea erorilor în modurile clasice este mai dificilă
- [ ] folosirea unei clase abstracte [*](https://github.com/Ionnier/poo/tree/main/labs/L04#clase-abstracte)
- [ ] clase template
  - [ ] crearea unei clase template [*](https://github.com/Ionnier/poo/tree/main/labs/L08)
  - [ ] 2 instanțieri ale acestei clase
- [ ] STL [*](https://github.com/Ionnier/poo/tree/main/labs/L07#stl)
  - [ ] utilizarea a două structuri (containere) diferite (vector, list sau orice alt container care e mai mult sau mai putin un array)
  - [ ] utilizarea a unui algoritm cu funcție lambda (de exemplu, sort, transform)
-  [ ] Design Patterns [*](https://github.com/Ionnier/poo/tree/main/labs/L08)
  - [ ] utilizarea a două șabloane de proiectare

### Observații

* Pot exista depunctări până la 2p pentru diferite aspecte precum:
  - memory leak-uri
  - nefolosirea destructorului virtual la nevoie
  - abuzarea de diferite concepte (toate funcțiile declarate virtual)
  - apelarea de funcții virtual în constructori

* În general, acestea sunt prezente în [CppCoreGuideline](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md), dar nu e nevoie să parcurgeți documentul, doar să scrieți codul suficient de organizat

* folderele `build/` și `install_dir/` sunt adăugate în fișierul `.gitignore` deoarece
conțin fișiere generate și nu ne ajută să le versionăm.
