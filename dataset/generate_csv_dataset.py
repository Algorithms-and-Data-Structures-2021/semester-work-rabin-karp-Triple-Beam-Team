import csv
from faker import Faker
from multiprocessing import Process

amount_samples = [100, 500, 1000, 5000, 10000, 25000, 50000, 100000, 250000, 500000, 750000, 1000000, 2500000, 5000000]
folders = ['text_data/data_1/',
           'text_data/data_2/',
           'text_data/data_3/',
           'text_data/data_4/', 'text_data/data_5/', 'text_data/data_6/',
           'text_data/data_7/', 'text_data/data_8/', 'text_data/data_9/',
           'text_data/data_10/']
files = ['100.csv', '500.csv', '1000.csv', '5000.csv', '10000csv', '25000.csv', '50000.csv', '100000csv', '250000.csv',
         '500000.csv', '750000.csv', '1000000.csv', '2500000.csv', '5000000.csv']


def write_in_files(folder_):
    fake = Faker()

    for file, j in zip(files, amount_samples):
        with open(folder_ + file, 'w', newline='') as csvfile:
            spamwriter = csv.writer(csvfile, delimiter=' ',
                                    quotechar='|',
                                    quoting=csv.QUOTE_MINIMAL)
            spamwriter.writerow([fake.pystr(max_chars=j)])


# To generate only certain dataset or certain quantity of text_data just exclude not needed files from the list above
if __name__ == '__main__':
    for folder in folders:
        p = Process(target=write_in_files, args=(folder,))
        p.start()
