items = LOAD '/user/input2/web-Google.txt' USING PigStorage('\t') AS (from:int, to:int);
group = GROUP items BY to;
wordcount = FOREACH group GENERATE grouped, COUNT(items);
store wordcount into 'my_WC_pig_out';
