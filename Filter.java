import java.util.*;

interface Criteria {
    boolean apply(String word);
}

public class Filter {
    public static void main(String args[]) {
      String[] arr = new String[]{"abc", "abcd", "bcd"};
      Criteria startsWithB = (word) -> {
          if(word.charAt(0) == 'b') return true;
          else return false;
      };
      ArrayList<String> result = new ArrayList<>();
      for(int i = 0; i < arr.length; i++){
          if(startsWithB.apply(arr[i])) result.add(arr[i]);
      }
      System.out.println(result.toString());
    }
}
