import java.util.Iterator;

class RLIterator implements Iterator<Character>{
    String str;
    int index = 0;
    int count = 0;

    public RLIterator(String str){
        if (str == null) throw new IllegalArgumentException("String cannot be null");
        if (str.length() % 2 != 0) throw new IllegalArgumentException("String length must be even");

        this.str = str;
        count = str.charAt(1)-'0';
    } //end-RLIterator
    
    public boolean hasNext(){
       return index < str.length();
    }
    
    public Character next(){
        if (!hasNext()) throw new java.util.NoSuchElementException();        
        char ch = str.charAt(index);

        if (--count == 0){
            index += 2;
            if (index < str.length())
                count = str.charAt(index+1)-'0';
        } // end-if

        return ch;
    } //end-next
} //end-RLIterator

public class RLIteratorTest {
    public static void main(String args[]){
        String str = "a3b5c1d7a6";
        Iterator<Character> iter = new RLIterator(str);
        
        while (iter.hasNext()){
            System.out.print(iter.next());
        } //end-while 
    } //end-main
}
