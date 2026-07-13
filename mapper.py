#!/usr/bin/env python3
import sys
"""
Mapper: Extracts customer and amount from transactions
Input: txn_id,customer,merchant,amount
Output: customer\tamount
"""
for line in sys.stdin:
    line = line.strip()
    fields = line.split(',')
    if len(fields) == 4:
        customer = fields[1]
        amount = fields[3]
        print(f'{customer}\t{amount}')
