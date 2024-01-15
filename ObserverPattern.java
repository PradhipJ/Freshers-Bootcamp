import java.util.*;

interface IObserver {
    public void update(String message);
}

class Dashboard implements IObserver{
    String message;
    public void update(String message){
        this.message = message;
    }
    public String getStatus(){
        return this.message;
    }
}

class Thread {
    String id;
    String state;
    String priority;
    String culture;
    ArrayList<IObserver> observers;
    
    public Thread(String id, String priority, String culture){
        this.id = id;
        this.state = "created";
        this.priority = priority;
        this.culture = culture;
        observers = new ArrayList<>();
    }
    
    private void notifyObservers(){
        for(IObserver observer: observers){
            observer.update(this.state);
        }
    }
    
    public void start(){
        this.state = "running";
        notifyObservers();
    }
    
    public void abort(){
        this.state = "aborted";
        notifyObservers();
    }
    
    public void sleep(){
        this.state = "sleeping";
        notifyObservers();
    }
    
    public void suspend(){
        this.state = "suspended";
        notifyObservers();
    }
    
    public void subscribe(IObserver observer){
        observers.add(observer);
    }
    
    public void unsubscribe(IObserver observer){
        observers.remove(observer);
    }
    
}

public class ObserverPattern {
    public static void main(String args[]) {
      Thread t = new Thread("1A", "low", "en-US");
      IObserver dashboard = new Dashboard();
      t.subscribe(dashboard);
      t.start();
      t.abort();
      t.sleep();
      dashboard.getStatus();
      t.suspend();
      t.unsubscribe(dashboard);
    }
}
