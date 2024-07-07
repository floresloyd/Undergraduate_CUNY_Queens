/**
 * @author Loyd Flores
 * CSCI 212 - OOP in Java
 * Submitted to: Prof. Lord & Prof. Zhai
 */
import java.awt.Container;
import java.awt.GridLayout;
import java.awt.TextArea;
import javax.swing.JFrame;
import javax.swing.*;

/**

 * WordGUI class - Sets all characteristics of GUI, JMenu, Menu options
 *
 */

public class  WordGUI extends JFrame{
	
	public TextArea areaInputText;
	public TextArea areaVowel;
	
		public WordGUI() {
	
		setSize(800,300);
		setLocation(200,200);
		setTitle("WordGUI");
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setLayout(new GridLayout(1,2));
		
		
		 JMenuItem   file;
		 JMenuItem   list;
		 
         JMenuBar    menuBar  = new JMenuBar();
         JMenu       fileMenu = new JMenu("File");
         JMenu       listMenu = new JMenu("List");
         FileMenuHandler fmh  = new FileMenuHandler(this);
         
         // Menu option OPEN
         file = new JMenuItem("Open");    
         file.addActionListener( fmh );
         fileMenu.add( file );

         fileMenu.addSeparator();           
       
         file = new JMenuItem("Quit");       
         file.addActionListener( fmh );
         fileMenu.add( file ); 
        
         // Menu option LIST 
         list = new JMenuItem("A");   
         list.addActionListener( fmh );
         listMenu.add( list );

         listMenu.addSeparator();         
         list = new JMenuItem("E");       
         list.addActionListener( fmh );
         listMenu.add( list );
         
         listMenu.addSeparator();   
         list = new JMenuItem("I");       
         list.addActionListener( fmh );
         listMenu.add( list );
         
         listMenu.addSeparator();   
         list = new JMenuItem("O");       
         list.addActionListener( fmh );
         listMenu.add( list ); 
         
         listMenu.addSeparator();   
         list = new JMenuItem("U");       
         list.addActionListener( fmh );
         listMenu.add( list );

         setJMenuBar(menuBar);
         menuBar.add(fileMenu);
         menuBar.add(listMenu);
		
		setVisible(true);
	}
}
