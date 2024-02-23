-- 코드를 작성해주세요
SELECT A.ITEM_ID, A.ITEM_NAME, A.RARITY
FROM (
    SELECT I.ITEM_ID, ITEM_NAME, RARITY, PARENT_ITEM_ID
FROM ITEM_INFO I LEFT OUTER JOIN ITEM_TREE T ON I.ITEM_ID = T.ITEM_ID
) AS A, ITEM_INFO B
WHERE A.PARENT_ITEM_ID = B.ITEM_ID AND B.RARITY = 'RARE'
ORDER BY A.ITEM_ID DESC;