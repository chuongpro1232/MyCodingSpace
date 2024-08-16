package eeet2580.stress_test_5.customer;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@RequestMapping("/customer")
public class CustomerController {

    @Autowired
    private CustomerService customerService;

    // ****** UNCOMMENT THE FOLLOWING ENDPOINTS WHEN YOUR JPA & MODEL ENTITY ARE
    // READY ******

    @GetMapping("/{email}")
    CustomerEntity getCustomerInfoByEmail(@PathVariable String email) {
        return customerService.getCustomerByEmail(email);
    }

    @PostMapping("")
    CustomerEntity createCustomer(@RequestBody CustomerEntity customerData) {
        return customerService.createCustomer(customerData);
    }

    @GetMapping("/balance/{email}")
    CustomerBalance getCustomerBalanceByEmail(@PathVariable String email) {
        return customerService.getCustomerBalance(email);
    }

}