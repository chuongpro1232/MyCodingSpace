package rmit.springboot_demo;

import org.springframework.boot.ApplicationArguments;
import org.springframework.boot.ApplicationRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

import rmit.springboot_demo.user_profile.UserProfileRespritory;

@SpringBootApplication
public class SpringbootDemoApplication implements ApplicationRunner {

	public static void main(String[] args) {
		SpringApplication.run(SpringbootDemoApplication.class, args);
	}

	@Override
	public void run(ApplicationArguments args) throws Exception {
		// TODO Auto-generated method stub
		//this step is just for demo in this moment
		UserProfileRespritory ups = new UserProfileRespritory();
		ups.initFakeUserProfiles();

	}










}
