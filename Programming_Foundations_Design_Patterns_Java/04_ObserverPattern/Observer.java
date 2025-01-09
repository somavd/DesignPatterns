import java.util.ArrayList;
interface Observer {
	public void update(int value);
}

class SimpleObserver implements Observer {
	private int value;
	private Subject simpleSubject;
	
	public SimpleObserver(Subject simpleSubject) {
		this.simpleSubject = simpleSubject;
		simpleSubject.registerObserver(this);
	}
	
	public void update(int value) {
		this.value = value;
		display();
	}
	
	public void display() {
		System.out.println("Value: " + value);
	}
}

interface Subject {
	public void registerObserver(Observer o);
	public void removeObserver(Observer o);
	public void notifyObservers();
}

class SimpleSubject implements Subject {
	private ArrayList<Observer> observers;
	private int value = 0;
	
	public SimpleSubject() {
		observers = new ArrayList<Observer>();
	}
	
	public void registerObserver(Observer o) {
		observers.add(o);
	}
	
	public void removeObserver(Observer o) {
		int i = observers.indexOf(o);
		if (i >= 0) {
			observers.remove(i);
		}
	}
	
	public void notifyObservers() {
		for (Observer observer : observers) {
			observer.update(value);
		}
	}
	
	public void setValue(int value) {
		this.value = value;
		notifyObservers();
	}
}

class Example {

	public static void main(String[] args) {
		SimpleSubject simpleSubject = new SimpleSubject();
	
		SimpleObserver simpleObserver = new SimpleObserver(simpleSubject);

		simpleSubject.setValue(80);
	}
}