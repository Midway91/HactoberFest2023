import csv
import fastavro

def convert_csv_to_avro(csv_file_path, avro_file_path):
    # Read the CSV file and convert it to Avro records
    avro_records = []
    with open(csv_file_path, 'r', encoding='latin-1') as csv_file:
        csv_reader = csv.reader(csv_file, delimiter=',')
        next(csv_reader)  # Skip the header row
        for row in csv_reader:
            if len(row) == 4:  # Check if the row has the expected number of columns
                avro_record = {
                    'Name': row[0],
                    'Age': int(row[1]),
                    'salary': float(row[2]),
                    'phone_number': row[3]
                }
                avro_records.append(avro_record)

    # Infer the Avro schema from the first record
    avro_schema = fastavro.infer_schema(avro_records[0])

    # Write the Avro records to an Avro file using the inferred schema
    with open(avro_file_path, 'wb') as avro_file:
        fastavro.writer(avro_file, avro_schema, avro_records)
# Example usage
csv_file_path = r'C:\\Users\\Dinesh.gupta\\Desktop\\personaldata.csv'
avro_file_path = r'C:\\Users\\Dinesh.gupta\\Desktop\\AVROFILES\\output.avro'

convert_csv_to_avro(csv_file_path, avro_file_path)
