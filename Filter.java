import java.util.*;

interface Criteria {
    boolean startsWithA(String word);
}

public class Filter {
    public static void main(String args[]) {
      String[] arr = new String[]{"abc", "abcd", "bcd"};
      Criteria criteria = (word) -> {
          if(word.charAt(0) == 'a') return true;
          else return false;
      };
      ArrayList<String> result = new ArrayList<>();
      for(int i = 0; i < arr.length; i++){
          if(criteria.startsWithA(arr[i])) result.add(arr[i]);
      }
      System.out.println(result.toString());
    }
}
