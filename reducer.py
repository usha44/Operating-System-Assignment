#!/usr/bin/env python3
import sys

FRAUD_THRESHOLD = 10000
current_customer = None
total_amount = 0

for line in sys.stdin:
    customer, amount = line.strip().split('\t')

    if current_customer != customer:
        if current_customer:
            status = 'FRAUD' if total_amount > FRAUD_THRESHOLD else 'NORMAL'
            print(f'{current_customer}\t{status}: ${total_amount:.2f}')
        current_customer = customer
        total_amount = 0

    total_amount += float(amount)

if current_customer:
    status = 'FRAUD' if total_amount > FRAUD_THRESHOLD else 'NORMAL'
    print(f'{current_customer}\t{status}: ${total_amount:.2f}')
