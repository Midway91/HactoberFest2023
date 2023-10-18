import React from 'react'
import { BrowserRouter as Router, Route, Routes, Navigate } from 'react-router-dom';

import ContactUs from './pages/ContactUs';

import Home_page from './pages/Home_page';

import AdminPanel from './pages/AdminPanel';

import StaffPanel from './pages/StaffPanel';

import PharmacyPanal from './pages/PharmacyPanal';

import Packages from './pages/Packages';

import 'bootstrap/dist/css/bootstrap.min.css';

import Staff from './pages/Staff';
import Nurse from './pages/Nurse';
import Doctor from './pages/Doctor';
import Patient from './pages/Patient';
import Equipment from './pages/Equipment';
import Payment from './pages/Payment';
import OurCenter from './pages/OurCenter';
import Meals from './pages/Meals';
import Kitchen from './pages/Kitchen_staff';
import Login from './pages/loginProfile';
import Signup from './pages/SignUpProfile';
import ChangePassword from './pages/changePassword';

function App() {
  return (
    <div className="App">
      <Router>
        <Routes>
          <Route path="/" element={<Home_page />} />
          <Route path="/contactus" element={<ContactUs />} />
          <Route path="/adminpanel" element={<AdminPanel />} />
          <Route path="/staffpanel" element={<StaffPanel />} />
          <Route path="/doctor" element={<Doctor />} />
          <Route path="/staff" element={<Staff />} />
          <Route path="/nurse" element={<Nurse />} />
          <Route path="/patient" element={<Patient />} />
          <Route path="/equipment" element={<Equipment />} />
          <Route path="/packages" element={<Packages />} />
          <Route path="/payment" element={<Payment />} />
          <Route path="/OurCenter" element={<OurCenter />} />
          <Route path="/PharmacyPanal" element={<PharmacyPanal />} />
          <Route path="/signup" element={<Signup />} />
          <Route path="/login" element={<Login />} />
          <Route path="/meals" element={<Meals />} />
          <Route path="/kitchen" element={<Kitchen />} />
          <Route path="/changePassword" element={<ChangePassword />} />
        </Routes>

      </Router>

    </div>
  );
}

export default App;
