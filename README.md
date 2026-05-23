# Memory-light-game

Voor deze overkoepelende opdracht werd gekozen voor een eigen versie van het klassieke memoryspel ‘Simon Says’. De keuze voor dit project kwam voort uit de wens om iets te maken dat niet alleen technisch interessant is, maar ook echt gebruikt en gespeeld kan worden. Een interactief spel leek daarom een leuke en motiverende uitdaging. Daarnaast hadden beide studenten nog geen ervaring met Arduino, waardoor er bewust gezocht werd naar een project dat haalbaar was, maar tegelijk voldoende uitdaging bood om nieuwe vaardigheden aan te leren.

Het spel combineert verschillende elektronische componenten, zoals LED’s, drukknoppen en een scorebord, waardoor het een leerrijke toepassing vormt binnen een Arduino-project. Bovendien biedt het project de mogelijkheid om zowel hardware als software met elkaar te laten samenwerken.

Het doel van het spel is om een steeds langer wordend lichtpatroon correct te onthouden en na te bootsen. Vier verlichte drukknoppen lichten één voor één op en vormen samen een bepaalde volgorde. Daarna is het aan de speler om deze volgorde correct opnieuw in te drukken. Wanneer de speler hierin slaagt, wordt het patroon uitgebreid met een extra stap, waardoor de moeilijkheidsgraad geleidelijk toeneemt. Bij een foutieve invoer eindigt het spel en moet de speler opnieuw beginnen.

fotooooooo/videooo

### Benodigdheden
* Arduino <br>
    Er werd een Arduino Nano 3 IOT gebruikt, omdat het initiële plan was om het scorebord via bleuthoot op de computer weer te geven. De bleuthoot werd niet gebruikt, dus een Arduino Nano werkt even goed voor dit project.
* Breadbord 2x
* LED's
    * rood
    * geel
    * blauw
    * groen <br>
    Andere kleuren kunnen ook gebruikt worden, besst wel altijd vier verschillende kleuren.
* Drukknoppen 5x
* Male to male jumper wires 16x <br>
    Gebruik een kleurcode voor overzicht.
* Micro USB kabel 
* Computer
    * Arduino IDE
    * Processing

### Reflectie
Tijdens dit project werd er veel bijgeleerd doordat er zelf veel moest worden uitgezocht en problemen moesten worden opgelost. Omdat er nog weinig ervaring was met Arduino, verliep niet alles meteen zoals gepland en werden er in het begin verschillende fouten gemaakt. Deze fouten waren echter leerrijk en zorgden voor een beter inzicht in hoe het systeem in elkaar zit.

* Er werd lange tijd enkel getest in Wokwi, waardoor de overstap naar de echte hardware later in het proces pas gebeurde Hierdoor kwamen sommige fouten pas laat aan het licht, wat extra aanpassingen noodzakelijk maakte. Dit toonde aan dat simulatie handig is, maar niet alle praktijkproblemen volledig kan vervangen.
    * Aansluiting van drukknoppen op breadbord
    * Kapotte LED
* Het scorebord was uiteindelijk het moeilijkste onderdeel van het project. Dit vergde veel trial-and-error en doorzettingsvermogen, maar zorgde uiteindelijk wel voor een werkend resultaat. [📃Schermproces](./documenten/scherm.md)
* Het schrijven van de code gebeurde in verschillende stappen, met veel testen tussendoor. Ook hierbij was veel trial-and-error nodig om fouten op te sporen en te verbeteren.

In het algemeen was dit een zeer leerrijk project waarin vooral probleemoplossend denken, geduld en stap-voor-stap werken centraal stonden.
