@FunctionalInterface
public interface ShareStrategy {
	public void share();
}

public class Email implements ShareStrategy {
	public void share() {
		System.out.println("I'm emailing the photo");
	}
}
public class Txt implements ShareStrategy {
	public void share() {
		System.out.println("I'm txting the photo");
	}
}
public class Social implements ShareStrategy {
	public void share() {
		System.out.println("I'm posting the photo on social media");
	}
}

public abstract class PhoneCameraApp {
	ShareStrategy shareStrategy;
	
	public void setShareStrategy(ShareStrategy shareStrategy) {
		this.shareStrategy = shareStrategy;
	}
	public void share() {
		shareStrategy.share();
	}
	public void take() {
		System.out.println("Taking the photo");
	}
	public void save() {
		System.out.println("Saving the photo");
	}
	public abstract void edit();
}

public class BasicCameraApp extends PhoneCameraApp {
	public void edit() {
		System.out.println("Basic editing features");
	}
}

public class CameraPlusApp extends PhoneCameraApp {
	public void edit() {
		System.out.println("Extra snazzy photo editing features");
	}
}

public class PhotoWithPhone {
 
	public static void main(String[] args) {
 
		PhoneCameraApp cameraApp = new BasicCameraApp();
		String share = getSharing();
		switch (share) {
			case("t"): cameraApp.setShareStrategy(new Txt()); break;
			case("e"): cameraApp.setShareStrategy(new Email()); break;
			case("s"): cameraApp.setShareStrategy(new Social()); break;
			default: cameraApp.setShareStrategy(new Txt());
		}
		cameraApp.take();
		cameraApp.edit();
		cameraApp.save();
		cameraApp.share();
	}
	public static String getSharing() {
		Scanner scanner = new Scanner(System.in);
		System.out.println("Share with txt (t), email (e), or social media (s)?");
		String appName = scanner.next();
		scanner.close();
		return appName;
	}
}
