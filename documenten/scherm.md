De score werd reeds correct weergegeven in de Serial Monitor, maar het was de bedoeling om deze op een apart scherm te tonen. Uiteraard werd er in de code aanpassingen gedaan om dit scorebord te laten werken. Zo moet het telkens met een punt worden opgeteld bij een juist antwoord en terug naar nul gaan bij een fout. Als er een fout wordt gemaakt, moet dit ook duidelijk via tekst verschijnen op het scherm zodat dit duidelijk is voor de speler. 

### Protopie connect
Eerst werd geprobeerd om dit via Protopie Connect te realiseren. De scores kwamen correct binnen in Protopie Connect. Er werd gezorgd dat enkel het cijfer van de score werd doorgestuurd, aangezien dit de enige benodigde informatie was. 
Toch kon de verbinding met de pie niet worden omgezet. Er werd geprobeerd met de functies receive en assign, maar het bleef onduidelijk welke waarden precies moesten worden ingevuld. Ook werd er gewerkt met een variabele, maar dit bracht geen oplossing.
<p align="center">
  <img src="../images/protopie connect 1.png" width="80%">
</p>
<p align="center">
  <img src="../images/protopie connect 2.png" width="80%">
</p>
 
### LCD
Vervolgens werd er overgeschakeld naar een LCD-scherm. De code leek eenvoudig te implementeren. Hiervoor moest wel een library geïnstalleerd worden. Dit lukte, maar bij het uploaden naar de Arduino verscheen een foutmelding dat de library niet geïnstalleerd was.
<p align="center">
  <img src="../images/LCD afbeelding.png" width="100%">
</p>

### Wifi
Een andere mogelijkheid was een extern toestel, in dit geval een tablet aansluiten met de laptop over wifi. Via de Mit App inventor kan een scorebord makkelijk worden gerealiseerd en verbonden worden via Arduino die aangesloten is aan de laptop. Aangezien de tablet en de pc over wifi draadloos connecteren, is het belangrijk dat deze op dezelfde wifi werken. 
Alles verliep op het eerste zich vlot, tot de library niet wou werken. Bleek dat deze enkel op 2,4 GHz werkt en de pc en tablet op een wifi van 5 GHz zijn aangesloten. 


<p align="center">
  <img src="../images/Mit app inventor.png" width="100%" >
</p>

### Processing
Een laatste optie was met het werken met de app Processing. Dit is een programmeertaal die vooral gebruikt wordt voor visueel beeldmateriaal weer te geven. Is gebasseerd op Java en kan zeer simpel geconnecteerd worden met de Arduino. Dit zal helaas niet via een extern scherm kunnen gebeuren dus zal deze op het laptopscherm zichtbaar zijn. 

<p align="center">
  <img src="" width="100%" >
</p>



