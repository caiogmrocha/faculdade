package com.example2.demo2.repositories;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.stereotype.Repository;

import com.example2.demo2.entities.Student;

@Repository
public interface StudentRepository extends JpaRepository<Student, Long> {}
