WITH A AS (SELECT CAR_ID
    , MONTH(START_DATE) AS MONTH
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
WHERE DATE_FORMAT(START_DATE, '%Y-%m') IN ('2022-08', '2022-09', '2022-10')
GROUP BY CAR_ID
HAVING COUNT(*) >= 5)

SELECT MONTH(START_DATE) AS MONTH
    , CAR_ID
    , COUNT(*) AS RECORDS
FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
WHERE CAR_ID IN (SELECT CAR_ID FROM A)
    AND DATE_FORMAT(START_DATE, '%Y-%m') IN ('2022-08', '2022-09', '2022-10')
GROUP BY MONTH, CAR_ID
ORDER BY MONTH ASC, CAR_ID DESC

# SELECT MONTH(START_DATE) AS MONTH, CAR_ID, COUNT(*) AS RECORDS
# FROM CAR_RENTAL_COMPANY_RENTAL_HISTORY
# WHERE DATE_FORMAT(START_DATE, '%Y-%m') IN ('2022-08', '2022-09', '2022-10')
# GROUP BY CAR_ID
# ORDER BY MONTH ASC, CAR_ID DESC