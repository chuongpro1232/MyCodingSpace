package eeet2580.stress_test_5.customer;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

@Component
class CustomerService {

    // ****** UNCOMMENT THE FOLLOWING ENDPOINTS WHEN YOUR JPA & MODEL ENTITY ARE
    // READY ******

    @Autowired
    private CustomerRepository customerRepository;

    CustomerEntity getCustomerByEmail(String email) {
        return customerRepository.findByEmail(email);
    }

    CustomerEntity createCustomer(CustomerEntity customerEntity) {
        return customerRepository.save(customerEntity);
    }

    CustomerBalance getCustomerBalance(String email) {
        return customerRepository.getCustomerEntityByEmail(email);
    }

}
