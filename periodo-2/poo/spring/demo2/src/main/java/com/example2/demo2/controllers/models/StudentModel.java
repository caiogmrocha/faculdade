package com.example2.demo2.controllers.models;

import org.hibernate.validator.constraints.Email;
import org.hibernate.validator.constraints.Length;
import org.hibernate.validator.constraints.NotBlank;

import com.example2.demo2.entities.Student;

@
public class StudentModel {
    @NotBlank
    private String name;
    
    @NotBlank
    @Email
    private String email;

    @NotBlank
    @Length(min = 10, max = 10)
    private String phone;

    @NotBlank
    @Length(min = 10, max = 10)
    private String registrationNumber;

    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
    public String getEmail() {
        return email;
    }
    public void setEmail(String email) {
        this.email = email;
    }
    public String getPhone() {
        return phone;
    }
    public void setPhone(String phone) {
        this.phone = phone;
    }
    public String getRegistrationNumber() {
        return registrationNumber;
    }
    public void setRegistrationNumber(String registrationNumber) {
        this.registrationNumber = registrationNumber;
    }

    public Student toEntity() {
        Student student = new Student();

        student.setName(name);
        student.setEmail(email);
        student.setPhone(phone);
        student.setRegistrationNumber(registrationNumber);
        
        return student;
    }
}
