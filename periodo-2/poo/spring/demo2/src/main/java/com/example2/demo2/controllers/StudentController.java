package com.example2.demo2.controllers;

import java.util.List;

import javax.validation.Valid;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RestController;

import com.example2.demo2.controllers.models.StudentModel;
import com.example2.demo2.entities.Student;
import com.example2.demo2.repositories.StudentRepository;

@RestController
public class StudentController {
    @Autowired
    StudentRepository studentRepository;

    @GetMapping("/students")
    public List<Student> getStudents() {
        return studentRepository.findAll();
    }

    @PostMapping("/students")
    public Student createStudent(@RequestBody @Valid StudentModel student) {
        return studentRepository.save(student.toEntity());
    }
}
