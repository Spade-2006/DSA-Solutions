-- Write your PostgreSQL query statement below

select Person.firstname , Person.lastName , Address.city , Address.state from Person Left Join Address on Person.personId = Address.personId;