package eeet2580.stress_test_5.customer;

import org.springframework.data.jpa.repository.JpaRepository;

public interface CustomerRepository extends JpaRepository<CustomerEntity, Integer> {
    CustomerEntity findByEmail(String email);

    CustomerBalance getCustomerEntityByEmail(String email);
}
