-- 177. Nth Highest Salary
-- Description:
-- Write a SQL query to get the nth highest salary from the Employee table.
-- +----+--------+
-- | Id | Salary |
-- +----+--------+
-- | 1  | 100    |
-- | 2  | 200    |
-- | 3  | 300    |
-- +----+--------+

-- For example, given the above Employee table, the nth highest salary where n = 2 is 200. 
-- If there is no nth highest salary, then the query should return null.
-- +------------------------+
-- | getNthHighestSalary(2) |
-- +------------------------+
-- | 200                    |
-- +------------------------+

-- LIMIT usage:

-- SELECT column1, column2,...
-- FROM table
-- LIMIT offset, count;

-- OR

-- SELECT column1, column2,...
-- FROM table
-- LIMIT count OFFSET offset;

-- offset: the first row offset of the return
-- count: max number of rows of return 

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
DECLARE M INT;
SET M = N - 1; -- important!
  RETURN (
      # Write your MySQL query statement below.
      SELECT DISTINCT Salary 
      FROM Employee 
      ORDER BY Salary DESC 
      LIMIT M, 1
  );
END

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
DECLARE M INT;
SET M = N - 1; -- important!
  RETURN (
      # Write your MySQL query statement below.
      SELECT DISTINCT Salary 
      FROM Employee 
      ORDER BY Salary DESC 
      LIMIT 1 OFFSET M
  );
END