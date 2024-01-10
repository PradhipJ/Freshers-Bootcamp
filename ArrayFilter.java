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

class StartsWithStrategy {
    private String startString;
    public void setStartsWith(String key){
        this.startString = key;
    }
    public boolean invoke(String item){
        return item.startsWith(startString);
    }
}

class StringListFilterController {
    StartsWithStrategy predicate = new StartsWithStrategy();
    public ArrayList<String> filter(ArrayList<String> stringList){
        ArrayList<String> filteredArray = new ArrayList<>();
        predicate.setStartsWith("a");
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
      
      StringListFilterController stringListFilterControllerObj = new StringListFilterController();
      ArrayList<String> filteredArray = stringListFilterControllerObj.filter(arr);
      
      ConsoleDisplayController consoleDisplayControllerObj = new ConsoleDisplayController();
      consoleDisplayControllerObj.setContent(filteredArray);
      consoleDisplayControllerObj.display();
    }
}
