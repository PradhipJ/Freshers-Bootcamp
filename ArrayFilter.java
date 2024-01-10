import java.util.stream.Stream;
import java.util.function.Predicate;
import java.util.*;

class ConsoleDisplayController {
    private ArrayList<String> content;
    public void setContent(ArrayList<String> msg){
        this.content = msg;
    }
    public void display(){
        System.out.print(content.toString());
    }
}

interface SearchStrategy {
    public boolean invoke(String item);
}

class StartsWithStrategy implements SearchStrategy {
    private String startString;
    public void setStartsWith(String key){
        this.startString = key;
    }
    public boolean invoke(String item){
        return item.startsWith(startString);
    }
}

class StringListFilterController {
    SearchStrategy predicate;
    public StringListFilterController(SearchStrategy searchStrategyObj){
        this.predicate = searchStrategyObj;
    }
    public ArrayList<String> filter(ArrayList<String> stringList){
        ArrayList<String> filteredArray = new ArrayList<>();
        for(String word: stringList){
            if(predicate.invoke(word)) filteredArray.add(word);
        }
        return filteredArray;
    }
}

public class ArrayFilter {
    public static void main(String args[]) {
      ArrayList<String> arr = new ArrayList<>();
      
      arr.add("abc");
      arr.add("bcd");
      arr.add("acd");
      
      StartsWithStrategy searchStrategyObj = new StartsWithStrategy();
      searchStrategyObj.setStartsWith("a");
      
      StringListFilterController stringListFilterControllerObj = new StringListFilterController(searchStrategyObj);
      ArrayList<String> filteredArray = stringListFilterControllerObj.filter(arr);
      
      ConsoleDisplayController consoleDisplayControllerObj = new ConsoleDisplayController();
      consoleDisplayControllerObj.setContent(filteredArray);
      consoleDisplayControllerObj.display();
    }
}
