/**
 * @author Loyd Flores
 * CSCI 212 - OOP in Java
 * Submitted to: Prof. Lord & Prof. Zhai
 * 
 * Exceptions to throw when given an invalid line number 
 */
public class InvalidWordLineException extends IllegalArgumentException{

   public InvalidWordLineException(String message) {
      super(message);
   }

}
