import { useState } from 'react';
import axios from 'axios';
import Swal from 'sweetalert2';

export const useChangePassword = () => {
    const [error, setError] = useState(null);
    const [isLoading, setIsLoading] = useState(false);

    const popupSuccessfull = () => {
        Swal.fire({
          position: 'top-end',
          icon: 'success',
          title: 'You successfully changed your password!',
          showConfirmButton: false,
          timer: 1500
        })
      };

    const changePassword = async ({ email, role,currentPassword, newPassword, confirmNewPassword }) => {
        setIsLoading(true);
        setError(null);
        try {
            const response = await axios.post('http://localhost:8070/user/changepassword', {
                email, role,currentPassword, newPassword, confirmNewPassword
            });
            if (response.status === 200) {
                // Handle successful reset, if needed
                localStorage.setItem('user', JSON.stringify(response.data));
                popupSuccessfull();
                return response.data;
            } else {
                setError(response.data.error);
            }
        } catch (error) {
            if (error.response) {
                setError(error.response.data.error);
            } else {
                setError('An error occurred while changing the password.');
            }
        } finally {
            setIsLoading(false);
        }
    };

    return { changePassword, isLoading, error };
};
