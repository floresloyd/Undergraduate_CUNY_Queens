/**
 * @author Loyd Flores
 * CSCI 212 - OOP in Java
 * Submitted to: Prof. Lord & Prof. Zhai
 */
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.io.*;
import javax.swing.JFileChooser;
import java.util.Scanner;
import java.util.ListIterator;
import java.util.Collections;
import java.util.LinkedList;
import java.util.regex.*;
import java.util.regex.Pattern;
import java.util.regex.Matcher;

public class FileMenuHandler implements ActionListener {
   JFrame jframe;
   TextArea areaInputText = new TextArea();
   TextArea areaVowel = new TextArea();
   LinkedList <WordLine> list = new LinkedList();
   
   public FileMenuHandler (JFrame jf) {
      jframe = jf;
   }
/**
 * @actionPerformend - Action listener is implemented
 * @param Event - Takes in what the user clicks as a parameter 
 * Vowels will all have the same contents and will only differ in the vowel to be searched
 */
   public void actionPerformed(ActionEvent event) {
      String menuName = event.getActionCommand();
      if (menuName.equals("Open"))
         openFile();
      else if (menuName.equals("Quit"))
          System.exit(0);
      else if (menuName.equals("A")) {
        //WordLine n1 = new WordLine("word",-1); // Uncomment to test InvalidWordLineException 
         areaVowel.setText(null);                // Every time a different letter is selected we clear out the previous set
         ListIterator<WordLine> iterator = list.listIterator(); // Iterate through text
         WordLine next;
            while(iterator.hasNext()) {
               next = iterator.next();
                  if(next.data.length() > 0 && next.data.substring(0,1).equalsIgnoreCase("A")){
                     areaVowel.append(next.lineNumber+ " " +next.data + "\n");
                  }
            }   
      } 
      else if (menuName.equals("E")) {
         areaVowel.setText(null);
         ListIterator<WordLine> iterator = list.listIterator();
         WordLine next;
            while(iterator.hasNext()) {
               next = iterator.next();
                  if(next.data.length() > 0 && next.data.substring(0,1).equalsIgnoreCase("E")){
                     areaVowel.append(next.lineNumber+ " " +next.data + "\n");
                  }
            }   
      } 
         
      else if (menuName.equals("I")) {
         areaVowel.setText(null);
         ListIterator<WordLine> iterator = list.listIterator();
         WordLine next;
            while(iterator.hasNext()) {
               next = iterator.next();
                  if(next.data.length() > 0 && next.data.substring(0,1).equalsIgnoreCase("I")){
                     areaVowel.append(next.lineNumber+ " " +next.data + "\n");
                  }
            }   
      }  
      else if (menuName.equals("O")) {
         areaVowel.setText(null);
         ListIterator<WordLine> iterator = list.listIterator();
         WordLine next;
            while(iterator.hasNext()) {
               next = iterator.next();
                  if(next.data.length() > 0 && next.data.substring(0,1).equalsIgnoreCase("O")){
                     areaVowel.append(next.lineNumber+ " " +next.data + "\n");
                  }
            }   
      } 
      else if (menuName.equals("U")) {
         areaVowel.setText(null);
         ListIterator<WordLine> iterator = list.listIterator();
         WordLine next;
            while(iterator.hasNext()) {
               next = iterator.next();
                  if(next.data.length() > 0 && next.data.substring(0,1).equalsIgnoreCase("U")){
                     areaVowel.append(next.lineNumber+ " " +next.data + "\n");
                  }
            }   
      } 
   } //actionPerformed
   
   /**
    * @openFile - Opens JFile chooser when called. Has no parameters
    * 
    */
   public void openFile() {
   
      JFileChooser file_chooser = new JFileChooser();
      file_chooser.setDialogTitle("FILE CHOOSER");
      file_chooser.setFileSelectionMode(JFileChooser.FILES_AND_DIRECTORIES);
      
      if(file_chooser.showOpenDialog(null) == JFileChooser.APPROVE_OPTION) {
         readSource(file_chooser.getSelectedFile());
      }
      else {
         JOptionPane.showMessageDialog(null, "Invalid File");
      }
      
  }
   /**
    * @readSource - Function that takes care of the input file 
    *               Has error handling when a file is not chosen
    * @var chosen_file - User's selected file
    * @var myInput     - Scanner that goes through individual text files
    * @var inputLine   - scanner passes in text into inputLine variable
    * @var counter     - line counter 
    */
   public void readSource(File file) {
      String chosen_file = file.getPath();
      Scanner myInput = null;
      String inputLine;   
      int counter = 0;
       
      Container myContentPane = jframe.getContentPane();
      myContentPane.add(areaInputText, BorderLayout.EAST);
      myContentPane.add(areaVowel, BorderLayout.WEST);

      
         try {
            myInput = new Scanner(new File(chosen_file));
         }
         catch (FileNotFoundException e) {
            e.printStackTrace();
         }
         while(myInput.hasNextLine()) {
            counter++;
            inputLine = myInput.nextLine();
            areaInputText.append(counter + "  " +  inputLine + '\n');  
            jframe.setVisible(true);
  
            // Splitter to store each string into a WordLine object
            Pattern p = Pattern.compile("[^a-zA-Z]"); // pattern does not want anything that is not A-Z or a-z;
            Matcher m = p.matcher(inputLine);         // compares inputLine to our pattern
            String[] result = p.split(inputLine);     // takes every word from input 
            
               for(int i = 0; i<result.length; i++) {
                 WordLine word = new WordLine(result[i],counter);   // all words are now wordline objects
                 list.add(word);                                    // add wordline objects into a linked list || LinkedList is now a list of wordline objects
               }
         }
         Collections.sort(list);                                    // Sort the linked list
         jframe.setVisible(true);
   }
}

