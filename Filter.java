import java.util.*;

class Group {
    String[] members;
    String size;
    
    void Group(int size) {
        this.size = size;
        this.members = new String[size];
    }
    
    void addMembers(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter member names:");
        for(int i = 0; i < size; i++){
            members[i] = sc.next();
        }
    }
    
    ArrayList<String> filter(String criteria, char c){
        ArrayList<String> result = new ArrayList<>();
        for(int i = 0; i < size; i++){
            if(criteria.equals("starts with") && members[i].charAt(0) == c){
                result.add(members[i]);
            }
            else if(criteria.equals("ends with") && members[i].charAt(members[i].length - 1) == c){
                result.add(members[i]);
            }
        }
    }
}

public class Filter {
    public static void main(String args[]) {
        Group newGroup = new Group(5);
        newGroup.addMembers();
        newGroup.filter("starts with", 'a');
        System.out.println(newGroup.toString());
    }
}