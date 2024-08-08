package rmitvn.SpringBootArchitecture;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

import rmitvn.SpringBootArchitecture.customer.Customer;
import rmitvn.SpringBootArchitecture.customer.CustomerRepository;

@SpringBootApplication
public class SpringBootArchitectureApplication implements CommandLineRunner {

	@Autowired
	private CustomerRepository repository;

	public static void main(String[] args) {
		SpringApplication.run(SpringBootArchitectureApplication.class, args);
	}
	
	@Override
	public void run(String... args) {
	
		//save a few customers
		repository.save(new Customer("Jack", "Bauer"));
		repository.save(new Customer("Chloe", "O'Brian"));
		repository.save(new Customer("Kim", "Bauer"));
		repository.save(new Customer("David", "Palmer"));
		repository.save(new Customer("Michelle", "Dessler"));

		// fetch all customers
		System.out.println("Customers found with findAll():");
		System.out.println("-------------------------------");
		repository.findAll().forEach(customer -> {
			System.out.println(customer.toString());
		});
		System.out.println("");

		// fetch an individual customer by ID
		Customer customer = repository.findById(1L);
		System.out.println("Customer found with findById(1L):");
		System.out.println("--------------------------------");
		System.out.println(customer.toString());
		System.out.println("");

		// fetch customers by last name
		System.out.println("Customer found with findByLastName('Bauer'):");
		System.out.println("--------------------------------------------");
		repository.findByLastName("Bauer").forEach(bauer -> {
			System.out.println(bauer.toString());
		});
		System.out.println("");
	};
}
