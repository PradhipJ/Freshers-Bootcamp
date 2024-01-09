import java.util.*;

interface Criteria {
    boolean apply(String word);
}

public class Filter {
    static ArrayList<String> filterArray(String[] words, Criteria criteria){
        ArrayList<String> result = new ArrayList<>();
        for(int i = 0; i < words.length; i++){
          if(criteria.apply(words[i])) result.add(words[i]);
        }
        return result;
    }
    public static void main(String args[]) {
      String[] arr = new String[]{"abc", "abcd", "bcd"};
       Criteria startsWithB = (word) -> {
          if(word.charAt(0) == 'b') return true;
          else return false;
        };
      ArrayList<String> res = filterArray(arr, startsWithB);
      System.out.println(res.toString());
    }
}
