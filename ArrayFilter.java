import java.util.stream.Stream;
import java.util.function.Predicate;
import java.util.*;

class Printer {
    void print(String[] arr){
        for(String item: arr){
            System.out.print(item + " ");
        }
    }
}

class Criteria {
    Predicate<String> checkStringLength(int length){
        Predicate<String> lengthChecker = word -> word.length() == length;
        return lengthChecker;
    } 
}

class Sorter {
    String[] sort(String[] arr){
        String[] backup = Arrays.copyOf(arr, arr.length);
        Arrays.sort(backup);
        return backup;
    }
}

class StringFilter {
  
    String[] filterItems(String[] arr, Predicate<String> criteria){
        return Stream.of(arr)
              .filter(criteria)
              .toArray(String[]::new);
    }
} 


public class ArrayFilter {
    public static void main(String args[]) {
      String[] arr = new String[]{"bcd", "abc", "ab", "abcd"};
      StringFilter filterObj = new StringFilter();
      Criteria criteria = new Criteria();
      String[] filteredObjects = filterObj.filterItems(arr, criteria.checkStringLength(3));
      Sorter sorterObj = new Sorter();
      String[] sortedArray = sorterObj.sort(filteredObjects);
      Printer printerObj = new Printer();
      printerObj.print(sortedArray);
    }
}