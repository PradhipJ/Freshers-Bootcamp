import java.util.*;

interface Criteria {
    boolean apply(String word);
}

public class Filter {
    static ArrayList<String> filterArray(String[] words){
        Criteria startsWithB = (word) -> {
          if(word.charAt(0) == 'b') return true;
          else return false;
        };
        ArrayList<String> result = new ArrayList<>();
        for(int i = 0; i < arr.length; i++){
          if(startsWithB.apply(arr[i])) result.add(arr[i]);
        }
        return result;
    }
    public static void main(String args[]) {
      String[] arr = new String[]{"abc", "abcd", "bcd"};
      ArrayList<String> res = filterArray(arr);
      System.out.println(res.toString());
    }
}
