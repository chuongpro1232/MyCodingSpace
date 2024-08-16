package eeet2580.jpa_demo.customer;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

@Component
class CustomerService {

    @Autowired
    private CustomerRepository customerRepository;

    CustomerInfo getCustomerInfoById(int id) {
        return customerRepository.findById(id);
    }

    CustomerInfo createCustomerInfoById(CustomerInfo customerInfo) {
        return customerRepository.save(customerInfo);
    }

    CustomerInfoBalance getCustomerInfoNobalance(int id) {
        return customerRepository.findCustomerInfoById(id);
    }

    CustomerInfoBalance updateCustomerInfoNobalance(int id, String email) {
        CustomerInfo customerInfo = customerRepository.findById(id);
        customerInfo.setEmail(email);
        customerRepository.save(customerInfo);
        return customerRepository.findCustomerInfoById(id);
    }
}
