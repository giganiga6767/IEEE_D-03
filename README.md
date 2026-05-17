# AI-Enabled Smart Grid Monitoring System
Envision 2025-26 · NIT Karnataka IEEE Student Branch · Team D-03

## What this project does

This project builds a smart grid monitoring system that combines automatic power factor correction with AI-based monitoring. It continuously measures electrical parameters, detects faults, forecasts load demand, and predicts equipment failure — all visualized through a live web dashboard.

## Modules

**Automatic Power Factor Correction (APFC)**
Simulated in MATLAB/Simulink. The system measures voltage and current, calculates reactive power, and switches capacitor banks to correct the power factor. Uses an optimized algorithm that tests all 16 possible switching combinations and picks the best one. Corrects PF from 0.6–0.8 up to 0.98+.

**Anomaly Detection**
Uses an Isolation Forest model to detect voltage faults and power factor degradation in real time. Achieved F1-score of 0.94.

**Load Forecasting**
Three models benchmarked — XGBoost, ANN, and LSTM — for 15-minute ahead active and reactive power forecasting. XGBoost performed best with R² of 0.997 on reactive power.

**Predictive Maintenance**
Random Forest Regressor predicts equipment health on a 0–1 scale. Scores below 0.3 are healthy, 0.3–0.7 means schedule inspection, above 0.7 is critical. Achieved R² of 0.908.

**Live Dashboard**
Built with Streamlit. Three tabs — live monitor with real-time gauges and alerts, load forecasting graphs, and equipment health trends.

## Tech used

Python, NumPy, Pandas, Scikit-learn, XGBoost, TensorFlow/Keras, Streamlit, Matplotlib, Plotly, MATLAB/Simulink, Arduino.

## Data

Synthetic dataset simulating 30 days of smart grid sensor readings at 15-minute intervals. Includes day/night load patterns, injected fault anomalies (2%), and gradual equipment degradation events.

## Team

Mentors — Reuben Abraham Jacob, Namith AP, Suhail Mohamed

Mentees — Vihaan Sunil, Gandu Niranjan, Abel Geo Tomy, Addle Antony Jais, Viren Garg

## Links

https://github.com/ReubenAbrahamJacob/AI-Enabled-Smart-Grid-Monitoring-System

https://github.com/namith17ap/Envision-26-D03
