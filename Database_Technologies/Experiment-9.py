!pip install mysql-connector-python

import mysql.connector
import pandas as pd

conn = mysql.connector.connect(user='root',password='pass@123',host='localhost',database='Experiment9')
cursor=conn.cursor()

data = pd.read_csv('customer1.csv')
data.head()

data.fillna('',inplace=True)
data.drop_duplicates(inplace=True)

data = data[data['email'].str.contains('@',na=False)]

print("Data transformed successfully.")

cols = ",".join([str(i) for i in data.columns.tolist()])

for i,row in data.iterrows():
    sql = f""" INSERT INTO customercleaned({cols})
        VALUES (%s, %s, %s, %s, %s)
        ON DUPLICATE KEY UPDATE
        first_name = VALUES(first_name),
        last_name = VALUES(last_name),
        country = VALUES(country),
        email = VALUES(email)"""
    cursor.execute(sql,(row['customer_Id'],row['first_name'],row['last_name'],row['country'],row['email']))


conn.commit()

cursor.close()

conn.close()

print("Data successfully stored in the 'customercleaned' table.")

output_file = 'transformed_customer.csv'
data.to_csv(output_file, index=False)

print(f"Data loaded into CSV file : {output_file}")
transformed_data = pd.read_csv(output_file)

# Display the first few rows (by default, it shows 5 rows)
print(transformed_data.head())

import matplotlib.pyplot as plt
import seaborn as sns

plt.figure(figsize=(10,6))
sns.countplot(x='country', data=data, palette='viridis')
plt.title("Number of Customers per Country")
plt.xlabel('Country')
plt.ylabel('Count of Customers')
plt.xticks(rotation=45)
plt.show()
