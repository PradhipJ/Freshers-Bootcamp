import org.springframework.context.ApplicationContext;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;

@Configuration
class AppConfig {

    @Bean
    public IFuelPump fuelPump() {
        return new FuelPump();
    }

    @Bean
    public IStartupMotor startupMotor() {
        return new StartupMotor();
    }

    @Bean
    public IEngine engine(IFuelPump fuelPump, IStartupMotor startupMotor) {
        return new Engine(fuelPump, startupMotor);
    }

    @Bean
    public ITransmission transmission() {
        return new Transmission();
    }

    @Bean
    public Car car(IEngine engine, ITransmission transmission) {
        return new Car(engine, transmission);
    }
}

interface ITransmission {
    
}

interface IEngine {
    
}

interface IFuelPump {
    
}

interface IStartupMotor {
    
}

class Car {
    IEngine engine;
    ITransmission transmission;
    public Car(IEngine engine, ITransmission transmission){
        this.engine = engine;
        this.transmission = transmission;
    }
}

class Engine implements IEngine {
    IFuelPump fuelpump;
    IStartupMotor startupmotor;
    public Engine(IFuelPump fuelpump, IStartupMotor startupmotor){
        this.fuelpump = fuelpump;
        this.startupmotor = startupmotor;
    }
}

class Transmission implements ITransmission {
    
}

class FuelPump implements IFuelPump {
    
}

class StartupMotor implements IStartupMotor {
    
}

public class DIContainer{
    public static void main(String args[]) {
       ApplicationContext context = new AnnotationConfigApplicationContext(AppConfig.class);
       Car car = context.getBean(Car.class);
      
    }
}