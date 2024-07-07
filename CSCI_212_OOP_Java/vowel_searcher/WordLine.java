/**
 * 
 * @author Loyd Flores
 * @var data - data or words within a WordLine Object
 * @var lineNumber - identifies where the data was selected from
 *
 */

public class WordLine implements Comparable<WordLine> {
String data;
int lineNumber;

   public WordLine(String word, int lineNumber) {
      
      if(lineNumber < 1) {
         throw new InvalidWordLineException("Invalid Line Number");     // Necessary Exceptions
      }
      this.data = word;
      this.lineNumber = lineNumber;
   }
   
   /**
    * Allows us to compare wordlane objects
    */
   @Override
   public int compareTo(WordLine o) {
      return this.data.compareTo(o.data);
   }
   
}
 